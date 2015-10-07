# interview study sheet
A quick study sheet I use as a refresher :smile:

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
* Self-balancing binary search tree
* Lookup, insertion, and deletion all take `O(log n)`

#### Trie
* Also called a *prefix tree*
* Stores subsequences of values; useful for autocomplete

### Hash Table
* **Hash function**: a function mapping an object to an integer such that if `a==b`, `H(a)==H(b)`
* A *hash table* is an array whose indices correspond to results from a hash function (implemented as a dictionary in Python)
* Provides `O(1)` lookup
* Collision resolution & table doubling

### Heap
* Special tree where nodes have higher (in the case of a min-heap) values than their parents
* Binary heap:
  * Heapify in `O(n)`
  * Find min in `O(1)`
  * Extract min, increase key, insert, delete in `O(log n)`
  * Can implement as a list where a node at index `i` has children at `2i+1` and `2i+2`

### Graph
* Collection of nodes and edges
* **Spanning tree**: a tree that includes all nodes in the graph
  * **Minimum spanning tree**: a spanning tree with minimum total edge weights

## Algorithms
### Binary Search
* Given a sorted list, start at the midpoint and divide and conquer
* `O(log n)`

### Sorting
#### Insertion
* Maintain a sorted sublist and insert new elements in it appropriately
* Sorts in-place; stable
* Best-case `O(n)`, average `O(n^2)`, worst `O(n^2)`

#### Bubble
* On each pass through the array, compare adjacent pairs of elements and swap if necessary
* Sorts in-place; stable
* Best-case `O(n)`, average `O(n^2)`, worst `O(n^2)`

#### Selection
* Exchange current element with smallest element to the right of the current element
* Sorts in-place; unstable
* Best-case `O(n^2)`, average `O(n^2)`, worst `O(n^2)`

#### Merge
* Recursively divide until sublists are size 1, then recursively merge the sublists
* Requires `O(n)` space; stable
* Best-case `O(n log n)`, average `O(n log n)`, worst `O(n log n)`

#### Quick
* Set a pivot in the array; move elements smaller than pivot to its left and elements larger to the right
  * Recursively sort left and right sublists
* Requires `O(log n)` space; stable
* Best-case `O(n log n)`, average `O(n log n)`, worst `O(n^2)`

#### Counting/Bucket
* For lists whose elements' values are in a set range
* Not a comparison sort so best & average is `O(n+k)` and worst is `O(n^2)`
* Iterate through list and place items in buckets; can be stable

#### Radix
* Apply a stable counting sort to every place value in a number
* Sort places from least to most significant
* Requires `O(n+k)` space; `O(d(n+k))` time
* Also not a comparison sort

### Graph Search
* Given a graph, find a path from a start node to an end node
* General strategy: expand a node, check to see if it's the goal node, add its children to the *search agenda*
* In the case of weighted graphs, a **heuristic** may help find the shortest path faster
  * **Admissible**: heuristic's value for a node is less than actual distance from node to goal (`H(n,G) ≤ dist(n,G)` for all nodes `n`)
  * **Consistent**: heuristic follows triangle inequality (`|H(A)-H(B)| ≤ dist(A,B)` for all nodes `A,B`)

#### Depth-first
* Implement with a stack (add new paths to the front of the agenda)

#### Breadth-first
* Implement with a queue (add new paths to the end of the agenda)
* In an unweighted graph, guaranteed to find shortest path

#### Hill-climbing
* Add new paths to the front of the agenda
* Sort *new* paths by terminal node's heuristic

#### Best-first
* Add new paths to the front of the agenda
* Sort *all paths* in agenda by terminal node's heuristic

#### Branch and bound
* Add new paths to the front of the agenda
* Sort agenda by path length so far
* Can also add a heuristic or extended set (or both)

#### A*
* Branch and bound with heuristic and extended set
* Heuristic must be consistent

## Other Concepts
### General
* Static/dynamic checking
* Strongly/weakly typed
* Compiled/interpreted
* Shallow/deep copying
* Immutable/mutable
* Greedy algorithms
* Defensive copying

### Asymptotic Notation
* Look [here](https://en.wikipedia.org/wiki/Big_O_notation#Formal_definition) for formal definitions
* O - asymptotic upper bound
  * o - asymptotic upper bound, excluding same rate
* Ω - asymptotic lower bound
  * ω - asymptotic lower bound, excluding same rate
* Θ - same asymptotic growth
* Exponential > polynomial > logarithmic > constant
* Can ask for worst, best, or average case

### Object-oriented Programming
Inspiration from [here](https://quizlet.com/22436874/oop-vocabulary-object-oriented-programming-flash-cards/)
* *Abstract data type*: access data only through a public interface; implementation can be changed without altering usage
* *Class*: basic concept in OOP, bundles data type information with actions
* *Object*: runtime value which belongs to a class
* *Encapsulation*: information hiding to ensure data integrity
* *Hierarchy*: classes can have super- and subclasses
* *Inheritance*: a subclass inherits data and methods from its parent classes
* *Overriding*: a subclass inherits parent methods but may override them
* *Polymorphism*: different classes in a program can respond to the same message in different ways; useful when an object's class can't be determined at compile time

### Concurrency
* TODO

### Design Patterns
* *Model-view-controller*: model stores data, controller updates model, view generates user interface
* *Factory method*: use a factory object to create other objects rather than using a constructor
* *Singleton*: restrict instantiation of a class to a single object
* *Observer*: subjects notify observers of any state changes (usually by calling their methods); used in MVC
* Lots more

### Dynamic Programming
* TODO

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
* [OSI Model](https://en.wikipedia.org/wiki/OSI_model)

### Recursion
* [*Master theorem*](https://en.wikipedia.org/wiki/Master_theorem): is most work performed in the root node, in the leaves, or evenly distributed in the rows of the recursion tree?

### Linux
* TODO

### Git
* `init`: creates/initializes `.git` folder in current directory
* `clone`: clone repo into new directory
* `pull`: fetch from another repo and integrate
    * `git pull` is same as `git fetch` then `git merge FETCH_HEAD`
* `add`: add files to index of contents for next commit
* `rm`: remove files from working tree and index
* `commit`: record changes to the repo, along with a commit message
* `rebase`: transplant changes on one branch to another
* `branch`: list, create, or delete branches
* `checkout`: switch branches
* `status`: show the working tree's status
* `diff`: show changes between commits or the working tree
* `log`: show commit logs in a repo
* `remote`: manage tracked remote repos
* `reset`: reset current HEAD to a different state

### Combinatorics
* `n(n-1)/2`: number of handshakes in a group
* `n-1`: number of rounds in a knockout tournament
* `2^k`: number of binary strings of length `k`
* `n!/(n-r)!`: permutations of `n` items taken `k` at a time
* `n!/(r!(n-r)!)`: combinations of `n` items taken `k` at a time

## Common Problems
* Anagrams
* Document distance
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
* `set()` or `{l}`: initialize
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
  * [Bitmasks](https://en.wikipedia.org/wiki/Mask_(computing))

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
* `copy`
  * `copy.copy(x)`: return shallow copy of `x`
  * `copy.deepcopy(x)`: return deep copy of `x`
* `collections` (use `collections.deque`)
  * `dq.pop()`, `dq.popleft()`, `dq.appendleft(val)`, `dq.extendleft(lst)`, `dq.rotate(n)`
* `heapq`
  * `heapq.push(heap,item)`: add an item
  * `heapq.pop(heap)`: pop an item
  * `heapq.heapify(l)`: make a list into a heap in linear time
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
  * When `__nonzero__()` returns `False`
  * When `__len__()` returns zero for a user-defined class
