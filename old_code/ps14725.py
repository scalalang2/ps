import sys
input = sys.stdin.readline

N = int(input())

trie = {
    'node': '',
    'children': {}
}

def add_trie(trie, nodes):
    if len(nodes) == 0:
        return

    if nodes[0] not in trie['children']:
        trie['children'][nodes[0]] = {
            'node': nodes[0],
            'children': {}
        }

    add_trie(trie['children'][nodes[0]], nodes[1:])

def print_trie(trie, depth):
    if trie['node'] != '':
        prefix = '--' * depth
        print(prefix + trie['node'])

    keys = list(trie['children'].keys())
    keys.sort()
    for i in range(len(keys)):
        key = keys[i]
        print_trie(trie['children'][key], depth + 1)

for _ in range(N):
    arr = input().split()
    add_trie(trie, arr[1:])

print_trie(trie, -1)