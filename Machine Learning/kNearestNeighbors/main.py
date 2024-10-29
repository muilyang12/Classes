from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn import metrics

from kNearestNeighbors import KNN

wine = datasets.load_wine()

X_train, X_test, y_train, y_test = train_test_split(
    wine.data, wine.target, test_size=0.3
)

knn = KNN(7)
knn.fit(X_train, y_train)
yTrainPred = knn.predict(X_train)
yPred = knn.predict(X_test)

print("Train Accuracy:", metrics.accuracy_score(y_train, yTrainPred))
print("Accuracy:", metrics.accuracy_score(y_test, yPred))
