## HW8

To compile this code, run the following command:

```g++ tree.cpp test_tree.cpp -o test -std=c++11``` 

### 1. TreeNode() -- constructor
- We assigned the arguments to the correct members of each TreeNode.

### 2. get_key()
- We return the key of the current TreeNode.

### 3. get_value()
- We return the value of the current TreeNode.

### 4. get_child()
- Takes in a character, either 'L' or 'R', and then returns a pointer to the current node's corresponding left or right TreeNode.

### 5. destroy_tree()
- Recursively goes through the entire tree, deleting all nodes beneath the current node before deleting the node itself.

### 6. path_to()
- Path_to first checks if the given k is in the root, and if so simply returns "". However, in the case that it's not that simple, it creates a string equal to the value of path_to_help, a recursive helper function. 
- Path_to_help recursively travels through the left subtree of the current node followed by the right, checking for a node whose key matches k and adding L or R if the string is not empty. If a match has been found, the first base case is met and the function returns F. The function is only able to add L or R to the string if the string is not empty, and the only situation in which the string is not empty is when the correct node has been found. The second base case simply returns an empty string once all other return statements have been skipped over, which occurs when a node doesn't match k and doesn't have any children.
- Then, path_to goes through this string and searches for the F, returning the string after removing F. However, if it doesn't find an F, then k must not exist, in which case it returns '-'. 

### 7. node_at()
- Takes in a string and indexes into each character of the string, traversing the tree as it goes through and returning the node it ends up at. 

### 8. insert()
- Starts by making a new node, and then goes straight to calling insert_help
- Insert_help() is a recursive helper function that traverses the tree by checking the value of k of the current node against the value of k being searched for
- If the current node's k is larger, it traverses left, otherwise right, until it reaches the bottom and appends the node

### 9. minimum()
- It goes left until there is no left no more. uh oh. wait. that's good actually. that means we got the minimum. Congrats. 

### 10. successor()
- Successor identifies one of two conditions, one where the current node has a subtree greater than itself, or when it has no subtrees greater than it.
- If it does have a subtree, it goes one to the right and then all the way to the left, since that will always be the closest value to the given one in that case.
- Otherwise, it moves up the tree so long as its parent is still smaller than itself. If it reaches a point where there is no parent greater than it, it returns nullptr.
- However, if at any point there is one that's greater, that is the successor, and it returns that node. 