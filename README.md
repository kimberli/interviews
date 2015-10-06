# interview study sheet

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [Data Structures](#data-structures)
- [Algorithms](#algorithms)
- [Other Concepts](#other-concepts)
- [Math](#math)
- [Common Problems](#common-problems)
- [Just Python Things](#just-python-things)
- [Problem-solving Strategies](#problem-solving-strategies)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

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
* 200 OK: success
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
### Strings
* `s.center(w,[fillchar])`: returns centered string in string of width `w`
* `s.count(sub[,start[,end]])`: returns count of non-overlapping occurences of substring
* `sub in s`: returns `True` if `sub` is in `s`
* `s.find(sub[,start[,end]])`: returns start index of substring or `-1`
* `s.join(iter)`: join items in iterable, separated by `s`
* `s.strip([chars])`: removing leading and trailing characters
* `s.replace(old,new[,count])`: returns copy of `s` with `old` replaced by `new`


### Lists
* `l=[]`: initialize
* `len(l)`: get size
* `l.append(val)`: append a value
* `l.insert(i,val)`: insert a value at position
* `l.extend(lst)`: append all values in a list
* `l.pop([i])`: remove an item and return it (defaults to last item)
* `x in l`: check membership
* `l.sort(cmp=None,key=None,reverse=False)`: sort in place
* `sorted(iterable[, cmp[, key[, reverse]]])`: return a new stably sorted list
* `l.reverse()`: reverse a list in place
* `range(start,end)`: get a list with items from `start` (inclusive) to `end` (exclusive)
* `[<expr> for <var> in <list> if <condition>]`: list functional
* `listname[start:end:slice_size]`: slicing

### Sets
* `set()` or `{[items]}`: initialize
* `len(s)`: get cardinality
* `x in s`: check membership
* `s | other | ...`: return a union of sets
* `s & other & ...`: return an intersection of sets
* `s - other - ...`: return difference of sets
* `s ^ other`: return set of elements uniquely in sets

### Dictionaries
* `d={}`: initialize
* `d[key]` or `d.get(key)`: get the value at `key` (the latter returns `None` if not found)
* `len(d)`: get item count
* `key in d`: check membership
* `d.pop(key)`: remove and return a value in the dictionary
* `del d[key]`: delete an item
* `d.update(other)`: update/overwrite with keys & values from `other`
* `d.items()`: return a list of `(key,value)` tuples
* `d.keys()`: return a list of dicionary keys
* `d.values()`: return a list of dictionary values

### Non-Decimal Numbers
* Binary numbers: preface with `0b`; use `bin(int)` to convert
  * Left and right shift: `<<` and `>>`
  * Bitwise AND, OR, XOR, NOT: `&`, `|`, `^`, `~`

### File I/O
* `f = open('filename', 'w')`: open a file
* `f.close()`: close file
* `f.readline()`: read a line from the file
* `for line in f`: iterate through lines in file
* `f.write()`: write a string to the file

### Magic Methods
* `__init__(self,[...)`: initializer for a class
* `__cmp__(self,other)`: return negative for `<`, 0 for `==`, positive for `>`
* `__eq__(self,other)`: define behavior for `==`
  * Also `ne`, `lt`, `le`, `gt`, `ge`
* `__str__(self)`: return string representation
* `__repr__(self)`: return machine-readable representation
* `__hash__(self)`: return an integer such that `a==b` implies `hash(a)==hash(b)`

### Useful Modules
* `collections` (use `collections.deque`)
  * `dq.pop()`, `dq.popleft()`, `dq.appendleft(val)`, `dq.extendleft(lst)`, `dq.rotate(n)`
* `heapd`
* `BeautifulSoup`
* `scipy`
* `numpy`
* `scikit-learn`
* `nltk`
* `requests`
* `unirest`

### Other
* Simultaneous assignment: `a,b = b,a` to swap
* `lambda x: <body>`: lambda function; don't need return statement
* Tuples are immutable lists
* Four numeric types: `int`, `long`, `float`, `complex`
* **Falsey values**:
  * `None`
  * `False`
  * Zero of any numeric type
  * Empty sequences & mappings
  * When `__len__()` returns zero for a user-defined class
