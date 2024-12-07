import numpy as np

from ucimlrepo import fetch_ucirepo
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

from LogisticRegression import LogisticRegression


def runLogisticRegression(X: np.ndarray, y: np.ndarray):
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)

    LR = LogisticRegression()
    LR.fit(X_train, y_train)
    y_train_pred = LR.predict(X_train)
    y_test_pred = LR.predict(X_test)

    train_accuracy = accuracy_score(y_train, y_train_pred)
    test_accuracy = accuracy_score(y_test, y_test_pred)

    return (train_accuracy, test_accuracy)


breast_cancer_wisconsin_diagnostic = fetch_ucirepo(id=17)

X = breast_cancer_wisconsin_diagnostic.data.features
y = breast_cancer_wisconsin_diagnostic.data.targets

y = y.to_numpy().reshape(-1)
class_mapping = {"M": 1, "B": 0}
y = np.array([class_mapping[label] for label in y])

train_accuracy, test_accuracy = runLogisticRegression(X, y)

print(f"Train Data Accuracy: {train_accuracy:.5f}")
print(f"Test Data Accuracy: {test_accuracy:.5f}")
