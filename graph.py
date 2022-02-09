class Queue:
	def __init__(self):
		self.coda = []
    
	def enqueue(self, elem):
	# adds one last item to the queue
	# @param elem: any type of data
	# @return None
		self.coda.append(elem)
    
	def dequeue(self):
	# ejects the first element of the queue
	# @return any type of data
		return self.coda.pop(0)
    
	def first(self):
	# returns the first element of the queue
	# @return any type of data
		return self.coda[0]
    
	def last(self):
	# returns the last element of the queue
	# @return any type of data
		return self.coda[-1]
    
	def empty(self):
	# returns true if the queue is empty false otherwise
	# return bool
		if len(self.coda) == 0:
			return True
		else:
			return False


class Graph:

	def __init__(self):
		self.nodes = {}

	def V(self):
		return self.nodes.keys()

	def size(self):
		return len(self.nodes)

	def adj(self, u):
		if u in self.nodes:
			return self.nodes[u]

	def insertNode(self, u):
		if u not in self.nodes:
			self.nodes[u] = {}

	def insertEdge(self, u, v, w=0):
		self.insertNode(u)
		self.insertNode(v)
		self.nodes[u][v] = w
	
	def graphTraversal(self, r):
		S = Queue()
		marker = []
		
		S.enqueue(r)
		marker.append(r)
		
		while(not S.empty()):
		
			u = S.dequeue()
			print("node:", u)
			
			for v in self.adj(u):
				print("edge:", u, "->", v)
				if(not v in marker):
					marker.append(v)
					S.enqueue(v)
					


graph = Graph()

for u,v in [ ('a','b'), ('a','d'), ('b','c'), ('d','a'), ('d','c'), ('d','e'), ('e','c'), ]:
	graph.insertEdge(u,v)

print("first way to print:")
for u in graph.V():
	print("node:", u, "->", graph.adj(u))

print("\nsecond way to print:")
graph.graphTraversal('a')
