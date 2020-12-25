import cyaron, os

os.system('g++ -o std -O2 ./std.cpp')

for i in range(10):

    io = cyaron.IO(file_prefix = 'sdfs', data_id = i + 1)

    if i < 6:
        n = cyaron.randint(5000, 10000)
    else:
        n = cyaron.randint(50000, 100000)
    m = cyaron.randint(n // 2, n * 2)

    graph = cyaron.Graph.graph(n, m, self_loop = False, repeated_edges = False)
    io.input_writeln(n, m)
    io.input_writeln(graph.to_str(output = cyaron.Edge.unweighted_edge))

    io.output_gen('./std')
    print('data{} generated'.format(i + 1))
