import numpy as np


class LogisticRegression:
    def __init__(self, learning_rate: float = 0.01, epochs: int = 1000):
        self.weights = None
        self.bias = None

        self.learning_rate = learning_rate
        self.epochs = epochs

    def fit(self, X_train: np.ndarray, y_train: np.ndarray) -> None:
        nSamples, nFeatures = X_train.shape

        self.weights = np.zeros(nFeatures)
        self.bias = 0

        for _ in range(self.epochs):
            z = np.dot(X_train, self.weights) + self.bias
            y_pred = self.sigmoid(z)

            dw = (1 / nSamples) * np.dot(X_train.T, (y_pred - y_train))
            db = (1 / nSamples) * np.sum(y_pred - y_train)

            self.weights -= self.learning_rate * dw
            self.bias -= self.learning_rate * db

    def predict(self, X_test) -> np.ndarray:
        z = np.dot(X_test, self.weights) + self.bias
        y_pred = self.sigmoid(z)

        return np.where(y_pred >= 0.5, 1, 0)

    def sigmoid(self, z: np.ndarray):
        return 1 / (1 + np.exp(-z))
