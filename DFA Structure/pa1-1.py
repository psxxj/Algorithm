#
#  Automata Programming Assignment #1 - 1
#
#  Name: 박성준 
#  ID: 20205075
#

import sys

def pa1_1(str_automata, str_input):
    
    # define the lists
    size_list = []
    Q = [] #states 
    I = [] #initial states
    F = [] #final states
    Sigma = [] #alphabet
    Delta = [] # transition function
    str_output = ["reject"]
    
    automata = str_automata.split("\n")
    for num in automata[0].split(" ")[1:]:
        size_list.append(num)      
    for states in automata[1].split(" "):
        Q.append(states)
    for initial in automata[2].split(" "):
        I.append(initial)
    for final in automata[3].split(" "):
        F.append(final)
    for alphabet in automata[4].split(" "):
        Sigma.append(alphabet)
    for i, transition in enumerate(automata[5:]):
        Delta.append([])
        for trans in transition.split(" "):
            Delta[i].append(trans)
    
    # recursive function to check acceptability
    def ReadNFA(state, string, count, l_state):
        # print(state, string, count, l_state) <<test>>

        if string == "" and state in F:
            str_output.append("accept") #success case
        
        else:
            for transition in Delta:
                if len(string) != 0 and transition[:2] == [state, string[0]]:
                    ReadNFA(transition[2], string[1:], count + 1, [transition[2]])
                elif transition[:2] == [state, "_"] and transition[2] not in l_state: #if lambda movings cause cycle, no need to search
                    ReadNFA(transition[2], string, count + 1, l_state + [transition[2]])
                else:
                    continue #fail case
    
    for initial_state in I:
        ReadNFA(initial_state, str_input, 0, [initial_state])
    
    return str_output[-1]


def main(*args):
    """File IO. Do not modify this function!"""
    if len(args) < 4:
        raise ValueError("Not enough arguments!")

    filename1 = args[1]
    filename2 = args[2]
    with open(filename1, "r") as fp1:
        text1 = fp1.read()
    with open(filename2, "r") as fp2:
        text2 = fp2.read()

    text3 = pa1_1(text1, text2)

    filename3 = args[3]
    with open(filename3, "w") as fp3:
        fp3.write(text3)

if __name__ == '__main__':
    args = sys.argv
    main(*args)
