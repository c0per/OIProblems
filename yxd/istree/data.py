import cyaron, os

os.system('g++ -o std -O2 ./std.cpp')

for i in range(10):

    io = cyaron.IO(file_prefix = 'istree', data_id = i + 1)

    t = cyaron.randint(5, 10)
    io.input_writeln(t)

    for j in range(t):
        if i < 2:
            n = cyaron.randint(100, 300)
        elif i < 4:
            n = cyaron.randint(9000, 10000)
        else:
            n = cyaron.randint(90000, 100000)


        if cyaron.randint(1, 2) == 1:
            io.input_writeln(n, n - 1)
            io.input_writeln(cyaron.Graph.tree(n).to_str(output = cyaron.Edge.unweighted_edge))
        else:
            m = cyaron.randint(n // 2, n * 2)
            io.input_writeln(n, m)
            io.input_writeln(cyaron.Graph.graph(n, m, self_loop=False, repeated_edges=False).to_str(output = cyaron.Edge.unweighted_edge))

    io.output_gen('./std')
    print('data{} generated'.format(i + 1))
