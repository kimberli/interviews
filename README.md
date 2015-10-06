# interview study sheet

## Data Structures
### Array
### Linked-list
* Singly vs doubly

### Stacks & Queues
* Double-ended queue

### Trees
* Tree vs forest
* structure etc

### Hash Table
* Dictionary, set

#### Binary Tree
#### n-ary Tree
#### AVL Tree
#### Trie

### Heap
### Graph

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
