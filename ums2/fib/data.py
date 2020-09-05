import cyaron, os

os.system('g++ -o std -O2 ./std.cpp')

for i in range(10):

    io = cyaron.IO(file_prefix = 'fib', data_id = i + 1)

    if i < 4:
        n = cyaron.randint(90, 100)
        m = cyaron.randint(90, 100)
        alimit = xlimit = (1, 100)
    elif i < 6:
        n = cyaron.randint(900, 1000)
        m = cyaron.randint(900, 1000)
        alimit = xlimit = (1, 1000)
    else:
        n = cyaron.randint(90000, 100000)
        m = cyaron.randint(90000, 100000)
        alimit = xlimit = (1, 1000000000)

    io.input_writeln(n, m)
    for j in range(n):
        io.input_write(cyaron.randint(*alimit))
    io.input_write('\n')

    for j in range(m):
        op = cyaron.choice([1, 2])
        l = cyaron.randint(1, n)
        r = cyaron.randint(l, n)
        if op == 1:
            io.input_writeln(op, l, r, cyaron.randint(*xlimit))
        else:
            io.input_writeln(op, l, r)

    io.output_gen('./std')
    print('data{} generated'.format(i + 1))
