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

entropyDecisionTree = DecisionTree(maxDepth=3, criterion="entropy")

entropyDecisionTree.fit(XTrain, yTrain)
yPredictWithEntropy = entropyDecisionTree.predict(XTest)
print("ScoreWithEntropy", accuracy_score(yTest, yPredictWithEntropy))

giniDecisionTree = DecisionTree(criterion="gini")

giniDecisionTree.fit(XTrain, yTrain)
yPredictWithGini = giniDecisionTree.predict(XTest)
print("ScoreWithGini", accuracy_score(yTest, yPredictWithGini))

import matplotlib.pyplot as plt
import networkx as nx


def plot_tree(node, feature_names):
    G = nx.DiGraph()

    # Node와 Edge 추가 함수
    def add_nodes_edges(node, graph, parent=None):
        if node is not None:
            # 현재 노드의 이름을 생성
            node_name = f"Node: {feature_names[node.feature] if node.feature is not None else 'Leaf'}\n"
            if node.isLeaf():
                node_name += f"Predict: {node.value}"
            else:
                node_name += f"{feature_names[node.feature]} <= {node.threshold:.2f}"

            # 그래프에 노드 추가
            graph.add_node(node_name)

            # 부모-자식 간 Edge 추가
            if parent:
                graph.add_edge(parent, node_name)

            # 왼쪽 및 오른쪽 자식으로 재귀 호출
            add_nodes_edges(node.left, graph, node_name)
            add_nodes_edges(node.right, graph, node_name)

    # 트리의 루트 노드부터 그래프 구축
    add_nodes_edges(node, G)

    # 그래프 시각화
    plt.figure(figsize=(10, 8))
    pos = nx.spring_layout(G)
    nx.draw(
        G, pos, with_labels=True, node_size=3000, node_color="skyblue", font_size=10
    )
    plt.title("Decision Tree Visualization")
    plt.show()


# 트리의 루트를 `entropyDecisionTree.tree`로 전달
plot_tree(entropyDecisionTree.tree, data.feature_names)
