import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.metrics import r2_score

from data import LinearRegressionData
from Visualize import LinearRegressionVisualize


x = LinearRegressionData.xFirst
y = LinearRegressionData.yFirst

xTrain, xTest, yTrain, yTest = train_test_split(x, y, test_size=0.2, random_state=5)

nSamples, nFeatures = xTrain.shape

w = np.zeros(nFeatures)
b = 0.0

learningRate = 0.01
epochs = 500

visualize = LinearRegressionVisualize(
    x,
    y,
    "Linear Regression with MAE",
    ["Percentage of lower status", "Average number of rooms"],
)

for epoch in range(epochs):
    yPred = np.dot(xTrain, w) + b

    error = yPred - yTrain

    dw = 1 / nSamples * np.dot(np.sign(error), xTrain)
    db = 1 / nSamples * np.sum(np.sign(error))

    w = w - learningRate * dw
    b = b - learningRate * db

    if epoch == epochs - 1:
        visualize.drawLine(w, b, isTempLine=False)
    elif epoch % 50 == 0:
        visualize.drawLine(w, b, isTempLine=True)


def rmse(predictions, targets):
    return np.sqrt(((predictions - targets) ** 2).mean())


yTrainFinal = np.dot(xTrain, w) + b

rmseTrain = rmse(yTrainFinal, yTrain)
r2Train = r2_score(yTrain, yTrainFinal)
print(f"Training RMSE = {rmseTrain}")
print(f"Training R2 = {r2Train}")

yTestFinal = np.dot(xTest, w) + b

rmseTest = rmse(yTestFinal, yTest)
r2Test = r2_score(yTest, yTestFinal)
print(f"Test RMSE = {rmseTest}")
print(f"Test R2 = {r2Test}")

visualize.updateDone()
