import pandas as pd
import numpy as np

from sklearn.datasets import load_wine
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

from DecisionTree import DecisionTree

data = load_wine()

X = data.data
y = data.target

XTrain, XTest, yTrain, yTest = train_test_split(X, y, test_size=0.3, random_state=42)

entropyDecisionTree = DecisionTree(criterion="entropy")

entropyDecisionTree.fit(XTrain, yTrain)
yPredictWithEntropy = entropyDecisionTree.predict(XTest)
print("ScoreWithEntropy", accuracy_score(yTest, yPredictWithEntropy))

giniDecisionTree = DecisionTree(criterion="gini")

giniDecisionTree.fit(XTrain, yTrain)
yPredictWithGini = giniDecisionTree.predict(XTest)
print("ScoreWithGini", accuracy_score(yTest, yPredictWithGini))
