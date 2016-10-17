class TreeNode:
	def __init__(self, payload):
		self.children = []
		self.payload = payload
	def height(self):
		return 1+max((child.height() for child in self.children),default=0)
	def walk(self, level=0):
		print(" "*level + self.payload)
		for child in self.children:
			child.walk(level + 1)


root = TreeNode("I am the root")
root.children.append(TreeNode("Child 1"))
subtree = TreeNode("Child 2")
subtree.children.extend([
	TreeNode("Child-child 1"),
	TreeNode("Child-child 2"),
])
root.children.append(subtree)

print("This tree looks like this:")
root.walk()
print("")
print("The height of the tree is:")
print(root.height())
