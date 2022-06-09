from typing import Dict

class Node:
    def __init__(self, value):
        self.value: str = value
        self.left: Node = None
        self.right: Node = None

    def preorder_traversal(self):
        print(self.value, end='')
        if self.left:
            self.left.preorder_traversal()
        if self.right:
            self.right.preorder_traversal()

    def inorder_traversal(self):
        if self.left:
            self.left.inorder_traversal()
        print(self.value, end='')
        if self.right:
            self.right.inorder_traversal()

    def postorder_traversal(self):
        if self.left:
            self.left.postorder_traversal()
        if self.right:
            self.right.postorder_traversal()
        print(self.value, end='')

Nodes: Dict[str, Node] = {}
N: int = int(input())
value:str
left:str
right:str
for _ in range(N):
    value, left, right = input().split()
    if value not in Nodes:
        Nodes[value] = Node(value)

    if left != '.':
        if left not in Nodes:
            Nodes[left] = Node(left)
            Nodes[value].left = Nodes[left]

    if right != '.':
        if right not in Nodes:
            Nodes[right] = Node(right)
            Nodes[value].right = Nodes[right]

Nodes['A'].preorder_traversal()
print()
Nodes['A'].inorder_traversal()
print()
Nodes['A'].postorder_traversal()