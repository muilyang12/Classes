import numpy as np
import matplotlib.pyplot as plt

import cv2
from sklearn.cluster import KMeans


class ImageColorQuantizer:
    def apply(self, image_path: str):
        image = cv2.imread(image_path)
        if image is None:
            print("Image not found.")

            return

        image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

        quantized_image_with_3 = self.quantize(image_rgb, 3)
        quantized_image_with_5 = self.quantize(image_rgb, 5)
        quantized_image_with_7 = self.quantize(image_rgb, 7)

        plt.figure()

        plt.subplot(2, 3, 2)
        plt.imshow(image_rgb)
        plt.title("Original Image")
        plt.axis("off")

        plt.subplot(2, 3, 4)
        plt.imshow(quantized_image_with_3)
        plt.title("Quantized with 3 colors")
        plt.axis("off")

        plt.subplot(2, 3, 5)
        plt.imshow(quantized_image_with_5)
        plt.title("Quantized with 5 colors")
        plt.axis("off")

        plt.subplot(2, 3, 6)
        plt.imshow(quantized_image_with_7)
        plt.title("Quantized with 7 colors")
        plt.axis("off")

        plt.show()

    def quantize(self, image: np.ndarray, numColors: int) -> np.ndarray:
        h, w, c = image.shape
        data = image.reshape((h * w, c))

        kmeans = KMeans(n_clusters=numColors, random_state=42)

        kmeans.fit(data)

        palette = kmeans.cluster_centers_.astype(np.uint8)
        labels = kmeans.labels_

        quantized_data = palette[labels].reshape((h, w, c))

        return quantized_data
