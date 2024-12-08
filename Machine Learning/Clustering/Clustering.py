import numpy as np


class Clustering:
    def __init__(self, method="mean", num_clusters: int = 3, epochs: int = 100):
        if method not in ["mean", "medoid"]:
            raise ValueError("Method must be 'mean' or 'medoid'")

        self.method = method
        self.num_clusters = num_clusters
        self.epochs = epochs

        self.centroids = None

    def fit(self, data: np.ndarray):
        # Initialize centroids randomly
        np.random.seed(42)
        self.centroids = data[
            np.random.choice(data.shape[0], self.num_clusters, replace=False)
        ]

        for epoch in range(self.epochs):
            clusters = self.get_closest_cluster(data)

            new_centroids = []

            for k in range(self.num_clusters):
                # Select data points belonging to the current cluster
                data_in_cluster = data[clusters == k]

                if self.method == "mean":
                    centroid = data_in_cluster.mean(axis=0)
                elif self.method == "medoid":
                    centroid = self.compute_medoid(data_in_cluster)

                new_centroids.append(centroid)

            self.centroids = np.array(new_centroids)

            if epoch % 10 == 0:
                error = self.calculate_error(data)

                print(f"Error: {error}")

    def predict(self, data: np.ndarray):
        return self.get_closest_cluster(data)

    def get_closest_cluster(self, points: np.ndarray):
        closest_cluster = []

        for point in points:
            distances = []

            for centroid in self.centroids:
                distance = np.linalg.norm(point - centroid)
                distances.append(distance)

            cluster_num = np.argmin(distances)
            closest_cluster.append(cluster_num)

        return np.array(closest_cluster)

    def compute_medoid(self, points: np.ndarray):
        distance_sums = []

        for point in points:
            distance_to_all_other_points = np.linalg.norm(point - points, axis=1)
            distance_sum = np.sum(distance_to_all_other_points)

            distance_sums.append(distance_sum)

        min_distance_sum_index = np.argmin(distance_sums)

        return points[min_distance_sum_index]

    def calculate_error(self, data):
        clusters = self.get_closest_cluster(data)

        error = 0

        for i, centroid in enumerate(self.centroids):
            cluster_points = data[clusters == i]

            error += np.sum(np.linalg.norm(cluster_points - centroid, axis=1))

        return error
