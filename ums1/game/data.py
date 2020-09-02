import cyaron, os

os.system('g++ -o std -O2 ./std.cpp')

for i in range(10):

    io = cyaron.IO(file_prefix = 'game', data_id = i + 1)

    if i < 4:
        n = cyaron.randint(18, 20)
    else:
        n = cyaron.randint(80, 100)

    io.input_writeln(n)

    for j in range(n):
        io.input_write(cyaron.randint(80, 100))

    io.output_gen('./std')
    print('data{} generated'.format(i + 1))
