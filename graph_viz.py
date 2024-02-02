import networkx as nx
import matplotlib.pyplot as plt

#opening the file
res = open("Results.txt", "r")
#reading the info
lines = res.readlines()
#deleting the '\n'-s
lines = [line.rstrip('\n') for line in lines]

#closing the file
res.close()

G = nx.Graph()

# for debugging print(lines)

names = lines[1].split()
colors = lines[2].split()
#getting, making nodes
for i in range(int(lines[0])):
    G.add_node(i, color = colors[i], name = names[i])
#getting, making edges
for i in range(3, len(lines)):
    nodes = lines[i].split()
    G.add_edge(int(nodes[0]), int(nodes[1]))
nx.draw(G, pos = nx.spiral_layout(G),width = 1,node_size = 4000, alpha = 0.7, with_labels=True, node_color=[G.nodes[n]['color'] for n in G.nodes()], labels={n: G.nodes[n]['name'] for n in G.nodes()})
plt.show()

