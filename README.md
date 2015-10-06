# interview study sheet

## Data Structures
### Array
* An *array* is a collection with specified size
  * Dynamic array: some languages' implementations automatically expand as you add elements
* Access elements directly by index
* Time complexity:
  * Access by index: `O(1)`
  * Search by value: `O(n)`
  * Insert: `O(n)` (need to shift values)
  * Delete: `O(n)` (need to shift values)

### Linked List
* A *linked list* is a collection of nodes where each node has a value and a reference
* **Singly-linked list**: nodes have pointers to the next node
* **Doubly-linked list**: nodes have pointers to next and previous nodes
* Time complexity:
  * Access by index: `O(n)`
  * Search by value: `O(n)`
  * Insert: `O(1)`
  * Delete: `O(1)`

### Stacks & Queues
* *Stack*: last in, first out (LIFO)
* *Queue*: first in, first out (FIFO)
* *Double-ended queue*: stack + queue combined
* Principal operations: `push` adds elements & `pop` extracts elements

### Trees
* A *tree* is an undirected, connected, acyclic graph
  * Has `v` vertices and `v-1` edges
  * Any two vertices are connected by a unique path
  * A **leaf** is a vertex of degree 1
  * One node is designated as the **root**
  * Each node has parent and/or children pointers
  * A node's height is the length of its path to the root
* A *forest* has multiple distinct trees (a disjoint union)
* An *n-ary tree* has at most `n` children per node

#### Binary Tree
* A *binary tree* has nodes with at most 2 children (designated left & right)
* **Full**: every node has 0 or 2 children
  * Number of nodes is at most `2^(h+1)-1`
* **Complete**: every level, except possibly the last, is filled, and the last level's nodes are as far left as possible
  * Number of internal nodes: `floor(n/2)`
* **Balanced**: has the minimum possible maximum depth
  * Height is `ceil(lg(n+1))`
* Traversals:
  * **Pre-order**: open current, visit left subtree, visit right subtree
  * **In-order**: visit left subtree, open current, visit right subtree (returns sorted list)
  * **Post-order**: visit left subtree, visit right subtree, open current
  * **Level-order**: breadth-first traversal, level by level

#### Binary Search Tree
* A *binary search tree* is an ordered binary tree
* Satisfies the BST property: each node's value is greater than all keys stored in the left subtree and less than all keys stored in the right subtree
* Designed to make searching faster--each comparison allows operations to skip about half the tree
* **Search**: recursively search subtrees; takes `O(h)`
* **Insertion**: like search, but insert node when a leaf is reached; takes `O(h)`
* **Deletion**: more complicated; takes `O(h)`
  * If deleting a node with no children, just do it
  * If deleting a node with a single child, replace the node with its subtree
  * If deleting a node with two children, swap with minimum value in right subtree or maximum value in left subtree, then delete the node (which should now be a leaf)

#### AVL Tree
#### Trie

### Hash Table
* Dictionary, set

### Heap
### Graph
* MST

## Algorithms
### Search
#### Depth-first
#### Breadth-first
#### Hill-climbing
#### Best-first
#### Branch and bound
#### A*

### Sorting
#### Insertion
#### Bubble
#### Selection
#### Merge
#### Quick
#### Counting
#### Radix

## Other Concepts
### General
* Static/dynamic checking
* Strongly/weakly typed
* Compiled/interpreted
* Shallow/deep copying
* Immutable/mutable
* Greedy algorithms

### Asymptotic Notation
### Object-oriented Programming
### Concurrency

### Design Patterns
* MVC
* Subscriber
* idk

### Dynamic Programming
### The Internet
#### HTTP Methods
* GET: used to retrieve data, no other effect on the data
* POST: used to send data to the server (e.g. form)
* PUT: replaces current representation of resource (idempotent)
* DELETE: remove current representation resource

#### HTTP Status Codes
* 204 OK: success
* 400 Bad Request: syntax could not be understood
* 401 Unauthorized: request not fulfilled due to lack of authorization
* 403 Forbidden: request understood but not fulfilled, authorization will not help
* 404 Not Found: URI could not be matched
* 408 Request Timeout: server did not receive a timely response from client
* 500 Internal Server Error: server exception
* 503 Service Unavailable: server unable to handle the request (temporary)
* 504 Gateway Timeout: server did not receive a timely response from upstream server

#### Networking
### Bit Manipulation
### Recursion
### Linux
### Git
* `init`: creates/initializes .git folder in current directory
* `clone`: clone repo into new directory
* `pull`: fetch from another repo and integrate
    * `git pull` is same as `git fetch` then `git merge FETCH_HEAD`
* `add`:
* `commit`:
* `rebase`:
* `branch`:
* `checkout`:
* `status`:
* `diff`:
* `log`:
* `remote`:
* `reset`:

## Math
### Combinatorics
## Common Problems
* Knapsack
* idk

## Just Python Things
### Lists
* `range(start,end)` gives the range `[start,end)`
* List functionals: `[<expr> for <var> in <list> if <condition>]`
* Lambda functions: `lambda x: <body>`; don't need return statement
* Slicing: `listname[start:end:slice_size]`

### Dictionaries
* `.items()` returns a list of `(key,value)` tuples
* `.values()`
* `.keys()`

### Non-Decimal Numbers
* Binary numbers: preface with `0b`; use `bin(int)` to convert
  * Left and right shift: `<<` and `>>`

### File I/O
* opening: ```f = open('filename', 'w')```
* closing
* reading
* writing


### Magic Methods
* __init__

### Useful Modules
* `collections`
* `heapd`
* `BeautifulSoup`
* 'scipy'
* 'numpy'
* 'scikit-learn'
* 'nltk'
* 'requests'
* 'unirest'

## Problem-solving Strategies
