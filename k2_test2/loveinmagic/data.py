import cyaron, os

os.system('g++ -o std -O2 ./std.cpp')

for i in range(10):

    io = cyaron.IO(file_prefix = 'loveinmagic', data_id = i + 1 )

    n = cyaron.randint(7, 8)
    m = cyaron.randint(3, 5)

    io.input_writeln(n, m)

    num2 = [x for x in range(1, n + 1)]
    num3 = [x for x in range(1, n + 1)]
    num4 = [x for x in range(1, n + 1)]

    for j in range(m):
        o = cyaron.randint(1, 4)
        if o == 1:
            x = cyaron.randint(1, n)
            y = cyaron.randint(1, n)
            while y == x:
                y = cyaron.randint(1, n)
        elif o == 2:
            if len(num2) < 2:
                j = j - 1
                continue
            x = cyaron.choice(num2)
            num2.remove(x)
            y = cyaron.choice(num2)
            num2.remove(y)
        elif o == 3:
            if len(num3) < 1:
                j = j - 1
                continue
            x = cyaron.choice(num3)
            num3.remove(x)
            y = cyaron.randint(0, 9)
        else:
            if len(num4) < 1:
                j = j - 1
                continue
            x = cyaron.choice(num4)
            num4.remove(x)
            y = cyaron.randint(0, 9)

        io.input_writeln(o, x, y)

    io.output_gen('./std')

    print('data{} generated'.format(i + 1))
