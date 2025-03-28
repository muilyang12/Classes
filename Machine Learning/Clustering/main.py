from sklearn.datasets import load_digits
import matplotlib.pyplot as plt

from Clustering import Clustering

digits = load_digits()
data = digits.data

clustering = Clustering(method="mean", num_clusters=10)
clustering.fit(data)
clusters_test = clustering.predict(data)

NUM_IMAGES = 10

images = data[:NUM_IMAGES]
cluster_labels = clusters_test[:NUM_IMAGES]

cluster_to_number = {cluster_labels[i]: i for i in range(10)}

for index, (image_data, cluster_num) in enumerate(zip(images, cluster_labels)):
    plt.subplot(2, NUM_IMAGES, index + 1)

    image = image_data.reshape(8, 8)
    plt.imshow(image, cmap=plt.cm.gray_r)
    plt.axis("off")

    plt.subplot(2, NUM_IMAGES, NUM_IMAGES + index + 1)

    plt.text(
        0.5, 0.5, cluster_to_number[cluster_num], ha="center", va="center", fontsize=24
    )
    plt.axis("off")

plt.show()
