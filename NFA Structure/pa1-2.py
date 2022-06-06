import sys

def pa1_2(str_input):
    
    # define the lists
    size_list = []
    Q = ['q0', 'q1', 'q2', 'q3', 'q4', 'q5', 'q6', 'q7', 'q8'] #states 
    I = ['q0'] #initial states
    F = ['q8'] #final states
    Sigma = [] #alphabet
    num = '0123456789'
    Delta = [[['q0', 'b', 'q1'], ['q0', 's', 'q3'], ['q0', '$', 'q6'], ['q0', num, 'q7']],
         [['q1', 'b', 'q1'], ['q1', 's', 'q3'], ['q1', '$', 'q6'], ['q1', num, 'q7'], ['q1', 'u', 'q2']],
         [['q2', 'b', 'q1'], ['q2', 's', 'q3'], ['q2', '$', 'q6'], ['q2', num, 'q7'], ['q1', 'y', 'q8']],
         [['q3', 'b', 'q1'], ['q3', 's', 'q3'], ['q3', '$', 'q6'], ['q3', num, 'q7'], ['q3', 'p', 'q4']],
         [['q4', 'b', 'q1'], ['q4', 's', 'q3'], ['q4', '$', 'q6'], ['q4', num, 'q7'], ['q4', 'a', 'q5']],
         [['q5', 'b', 'q1'], ['q5', 's', 'q3'], ['q5', '$', 'q6'], ['q5', num, 'q7'], ['q5', 'm', 'q8']],
         [['q6', 'b', 'q1'], ['q6', 's', 'q3'], ['q6', '$', 'q6'], ['q6', num, 'q8']],
         [['q7', 'b', 'q1'], ['q7', 's', 'q3'], ['q7', '$', 'q6'], ['q7', num, 'q7'], ['q7', '%', 'q8']]] # transition function
    str_output = ["nospam"]
        
    # recursive function to check spam / nospam
    def ReadNFA(state, string, count):
        # print(state, string, count)

        if state in F:
            str_output.append("spam") #trap final state for this NFA
        
        elif len(string) != 0:
            next_state = ''
            for transition in Delta[int(state[1])]:
                if string[0] in transition[1]:
                    next_state = transition[2]
                    break
            
            if next_state != '':
                ReadNFA(next_state, string[1:], count + 1)
            else:
                ReadNFA('q0', string[1:], count + 1)
                         
    ReadNFA(I[0], str_input, 0)
    
    return str_output[-1]

def main(*args):
    """File IO. Do not modify this function!"""
    if len(args) < 3:
        raise ValueError("Not enough arguments!")

    filename1 = args[1]
    with open(filename1, "r") as fp1:
        text1 = fp1.read()

    text2 = pa1_2(text1)

    filename2 = args[2]
    with open(filename2, "w") as fp2:
        fp2.write(text2)


if __name__ == '__main__':
    args = sys.argv
    main(*args)
