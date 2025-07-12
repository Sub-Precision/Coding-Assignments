// This question did  not ask for code, it asked for an explanation
// so i guess i am writing that here 

// The single source shortest path problem is an attempt to figure out the shortest path to any node, from any node
// one popular method of this is Dijsktra's Algorithm
// how Dijsktra's algorithm solves this is it starts at a root node, then evaluates and saves each path available,
// noting it's weight and giving a tag to that node with the label of the total weight to get there
// once all all adjacent nodes have been evaluated, it goes one level deeper on all adjacent nodes of those adjacent nodes,
// evaluating all total paths from them, then does the same thing, 
// tags those nodes with the total weight required to get there,
// it repeats this process until all nodes have been discovered, 
// then it deletes redundant paths that require more weight than other discovered paths to the same node