import cyaron, os

os.system('g++ -o std -O2 std.cpp')

for i in range(10):

    io = cyaron.IO(file_prefix = 'loveinoi', data_id = i + 1)
    para = cyaron.String.random_paragraph((1500, 1800), sentence_joiners='\n', sentence_terminators='.?')
    #print(para)

    io.input_write(para)
    io.output_gen('./std')

    print('data{} generated'.format(i + 1))
