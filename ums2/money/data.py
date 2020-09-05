import cyaron, os

os.system('g++ -o std -O2 ./std.cpp')

for i in range(10):

    io = cyaron.IO(file_prefix = 'money', data_id = i + 1)

    if i < 2:
        n = cyaron.randint(15, 20)
    elif i < 4:
        n = cyaron.randint(900, 1000)
    else:
        n = cyaron.randint(900000, 1000000)

    io.input_writeln(n)
    tree = cyaron.Graph.tree(n, weight_limit = (1, 1000000000))

    for j in range(n):
        io.input_write(cyaron.randint(1, 1000000000))
    io.input_write('\n')
    io.input_writeln(tree)

    io.output_gen('./std')
    print('data{} generated'.format(i + 1))
