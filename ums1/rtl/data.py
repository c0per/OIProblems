import cyaron, os, string

os.system('g++ -o std -O2 ./std.cpp')

for i in range(10):

    io = cyaron.IO(file_prefix = 'rtl', data_id = i + 1)

    n = cyaron.randint(2500, 3000)
    m = cyaron.randint(1, 26)
    charset = string.ascii_lowercase[:m]
    s = cyaron.String.random(n, charset = charset)

    io.input_writeln(s)

    for j in range(m):
        io.input_writeln(charset[j], cyaron.randint(1, 100000), cyaron.randint(1, 100000))

    io.output_gen('./std')
    print('data{} generated'.format(i + 1))
