import cyaron, os

os.system('g++ -o std -O2 ./std.cpp')

for i in range(10):

    io = cyaron.IO(file_prefix = 'home', data_id = i + 1)

    if i < 6:
        n = cyaron.randint(100, 200)
        m = cyaron.randint(5000, 10000)
        b = cyaron.randint(180, 200)
        w = (90, 140)
    else:
        n = cyaron.randint(9000, 10000)
        m = cyaron.randint(40000, 50000)
        b = cyaron.randint(900000000, 1000000000)
        w = (1200000, 18000000)

    io.input_writeln(n, m, b)

    for j in range(n):
        io.input_write(cyaron.randint(40000, 1000000000))
    io.input_write('\n')

    gra = cyaron.Graph.graph(n, m, weight_limit = w)
    io.input_writeln(gra.to_str(shuffle=True))
    io.output_gen('./std')
    print('data{} generated'.format(i + 1))
