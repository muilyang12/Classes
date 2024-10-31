from anytree import Node as AnyNode
import matplotlib.pyplot as plt


class TreeVisualizer:
    def __init__(self):
        self.fig, self.ax = plt.subplots()

    def drawTree(self, rootAnyNode, hightlightedNodeName=None):
        self.ax.clear()
        self.ax.set_axis_off()

        positions = self.calculateNodePostions(rootAnyNode)

        for node, (x, y) in positions.items():
            color = "red" if node.name == hightlightedNodeName else "lightblue"
            self.ax.text(
                x,
                y,
                node.name,
                ha="center",
                va="center",
                bbox=dict(facecolor=color, edgecolor="black", boxstyle="round,pad=0.3"),
            )

        for node, (x, y) in positions.items():
            for child in node.children:
                xChild, yChild = positions[child]

                self.ax.plot([x, xChild], [y, yChild], "k-")

        plt.draw()

        plt.show()

    def calculateNodePostions(self, node: AnyNode, x=0, y=0, widthGap=2, heightGap=1):
        positions = {node: (x, y)}

        children = list(node.children)

        if not children:
            return positions

        for i, child in enumerate(children):
            positions.update(
                self.calculateNodePostions(
                    child,
                    x + (i - 0.5) * self.countLeafNodes(child) * widthGap,
                    y - heightGap,
                )
            )
        return positions

    def countLeafNodes(self, node: AnyNode):
        if not node.children:
            return 1

        return sum(self.countLeafNodes(child) for child in node.children)
