from collections import deque

class Node:
  def __init__(self, value, left=None, right=None):
    self.value = value
    self.left = left
    self.right = right

  def __str__(self):
    # level-by-level pretty-printer
    nodes = deque([self])
    answer = ''
    while len(nodes):
      node = nodes.popleft()
      if not node:
        continue
      answer += str(node.value)
      nodes.append(node.left)
      nodes.append(node.right)
    return answer

def findParent(nums, start, end):
  n = end - start
  if n < 1:
    return None, None, None
  mid = start + n / 2
  return Node(nums[mid]), [start, mid], [mid+1, end]

def helper(nums, interval):
  root, l, r = findParent(nums, interval[0], interval[1])
  if (root != None):
    root.left = helper(nums, l)
    root.right = helper(nums, r)

  return root

def createBalancedBST(nums):
  return helper(nums, [0, len(nums)])

print createBalancedBST([1, 2, 3, 4, 5, 6, 7])