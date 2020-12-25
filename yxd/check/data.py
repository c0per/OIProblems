import cyaron, os

os.system('g++ -o std -O2 ./std.cpp')

for i in range(10):

    io = cyaron.IO(file_prefix = 'check', data_id = i + 1)

    n = cyaron.randint(500, 1000)
    m = cyaron.randint(n // 2, n * 2)
    if i < 6:
        q = cyaron.randint(500, 1000)
    else:
        q = cyaron.randint(500000, 1000000)

    graph = cyaron.Graph.graph(n, m, directed = True, self_loop = False, repeated_edges = False)

    io.input_writeln(n, m)
    io.input_writeln(graph.to_str(output = cyaron.Edge.unweighted_edge))
    io.input_writeln(q)
    for j in range(q):
        u = cyaron.randint(1, n)
        v = cyaron.randint(1, n)
        io.input_writeln(u, v)

    io.output_gen('./std')
    print('data{} generated'.format(i + 1))
