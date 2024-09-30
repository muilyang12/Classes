import pandas as pd
import numpy as np


class BostonHousingDataset:
    def __init__(self):
        self.url = "http://lib.stat.cmu.edu/datasets/boston"
        self.feature_names = [
            "CRIM",
            "ZN",
            "INDUS",
            "CHAS",
            "NOX",
            "RM",
            "AGE",
            "DIS",
            "RAD",
            "TAX",
            "PTRATIO",
            "B",
            "LSTAT",
        ]

    def load_dataset(self):
        # Fetch data from URL
        raw_df = pd.read_csv(self.url, sep="\s+", skiprows=22, header=None)
        data = np.hstack([raw_df.values[::2, :], raw_df.values[1::2, :2]])
        target = raw_df.values[1::2, 2]

        # Create the dictionary in sklearn format
        dataset = {
            "data": [],
            "target": [],
            "feature_names": self.feature_names,
            "DESCR": "Boston House Prices dataset",
        }

        dataset["data"] = data
        dataset["target"] = target

        return dataset


boston_housing = BostonHousingDataset()
boston_dataset = boston_housing.load_dataset()
boston_dataset.keys(), boston_dataset["DESCR"]

boston = pd.DataFrame(boston_dataset["data"], columns=boston_dataset["feature_names"])

boston["MEDV"] = boston_dataset["target"]

xFirst = pd.DataFrame(np.c_[boston["LSTAT"], boston["RM"]], columns=["LSTAT", "RM"])
xFirst = np.array(xFirst)
yFirst = boston["MEDV"]
yFirst = np.array(yFirst)

xSecond = pd.DataFrame(np.c_[boston["CHAS"], boston["B"]], columns=["CHAS", "B"])
ySecond = boston["MEDV"]
xSecond = np.array(xSecond)
ySecond = np.array(ySecond)
