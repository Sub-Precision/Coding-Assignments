import json
import queue as Q
from collections import deque

# Define possible moves (up, down, left, right)
MOVES = [(0, -1), (0, 1), (-1, 0), (1, 0)]
MOVE_NAMES = ['Left', 'Right', 'Up', 'Down']

# Function to calculate the Manhattan distance heuristic
# borrowed this function snippet from stack overflow
def manhattan_distance(state):
    distance = 0
    for i in range(len(state)):
        for j in range(len(state[0])):
            if state[i][j] != 0:
                x, y = divmod(state[i][j], len(state))
                distance += abs(x - i) + abs(y - j)
    return distance

# Function to check if a move is valid
def is_valid_move(x, y, size):
    return 0 <= x < size and 0 <= y < size

# Function to find the blank tile in the current state
def find_blank_tile(state):
    for i in range(len(state)):
        for j in range(len(state[0])):
            if state[i][j] == 0:
                return i, j

# Function to generate new states by making valid moves
def generate_states(state):
    x, y = find_blank_tile(state)
    new_states = []
    for dx, dy in MOVES:
        new_x, new_y = x + dx, y + dy
        if is_valid_move(new_x, new_y, len(state)):
            new_state = [row[:] for row in state]  # Create a copy of the current state
            new_state[x][y], new_state[new_x][new_y] = new_state[new_x][new_y], new_state[x][y]
            new_states.append((new_state, MOVE_NAMES[MOVES.index((dx, dy))]))
    return new_states

# Function to solve the puzzle using A* search
# used chatgpt to help with this function snippet
# as i am bad at solving these puzzles personally
# let alone teaching a computer how to do it
def solve_puzzle_A(start):
    visited = set()
    start_node = (start, 0, manhattan_distance(start), [])
    frontier = Q.PriorityQueue()
    frontier.put(start_node)
    generated_states = 0  # Counter for generated states
    explored_states = 0   # Counter for explored states

    while not frontier.empty():
        current_state, cost, heuristic, path = frontier.get()
        if current_state == goal:
            return path, generated_states, explored_states

        if tuple(map(tuple, current_state)) in visited:
            continue

        visited.add(tuple(map(tuple, current_state)))
        explored_states += 1

        for next_state, move_name in generate_states(current_state):
            generated_states += 1
            next_cost = cost + 1
            next_heuristic = manhattan_distance(next_state)
            next_path = path + [move_name]
            frontier.put((next_state, next_cost, next_cost + next_heuristic, next_path))

    return None, generated_states, explored_states

def solve_puzzle_Graph(initial_state):
    visited = set()
    queue = deque([(initial_state, [])])  # Queue stores (state, path)
    generated_states = 0  # Counter for generated states

    while queue:
        current_state, path = queue.popleft()
        generated_states += 1
        if current_state == goal:
            return path, generated_states, len(visited)

        if tuple(map(tuple, current_state)) in visited:
            continue

        visited.add(tuple(map(tuple, current_state)))

        for next_state, move_name in generate_states(current_state):
            next_path = path + [move_name]
            queue.append((next_state, next_path))

    return None, generated_states, len(visited)

# Function to print the puzzle state
def print_puzzle(state):
    for row in state:
        print(" ".join(map(str, row)))

# Function to read puzzle information from JSON data
def read_puzzle_from_json(json_data):
    puzzle_data = json.loads(json_data)
    n = puzzle_data["n"]
    start = puzzle_data["start"]
    goal = puzzle_data["goal"]
    return n, start, goal

# Main function
if __name__ == "__main__":
    # Read puzzle information from JSON
    json_data = """
    {
        "n": 3,
        "start": [
            [7, 2, 4],
            [5, 0, 6],
            [8, 3, 1]
        ],
        "goal": [
            [0, 1, 2],
            [3, 4, 5],
            [6, 7, 8]
        ]
    }
    """
    

# This first section generates the A* search, 
# because i found that one easier to implement so i started with it
    n, start, goal = read_puzzle_from_json(json_data)
    print("A* Search")
    print("Start State:")
    print_puzzle(start)

    solution_path, generated_states, explored_states = solve_puzzle_A(start)

    if solution_path:
        print("\nSolution Path:")
        for step, move in enumerate(solution_path, 1):
            print(f"Step {step}: {move}")
        print(f"\nSolution Length: {len(solution_path)} moves")
        print(f"Number of States Generated: {generated_states}")
        print(f"Number of States Explored: {explored_states}")
        print("\nGoal State:")
        print_puzzle(goal)
    else:
        print("\nNo solution found.")

    print()
    print()
    print()
    print()
    print()
    
# Decided to mash the 2 search algorithms together since they both use
# similar code blocks for the basic properties of the 8 slide puzzle
# to help consolidate the code

# but this section is the graph search section
    print("Graph Search")
    print("Start State:")
    print_puzzle(start)
    
    solution_path, generated_states, explored_states = solve_puzzle_Graph(start)
    if solution_path:
        print("\nSolution Path:")
        for step, move in enumerate(solution_path, 1):
            print(f"Step {step}: {move}")
        print(f"\nSolution Length: {len(solution_path)} moves")
        print(f"Number of States Generated: {generated_states}")
        print(f"Number of States Explored: {explored_states}")
# Print the final state
        final_state = start
        for move in solution_path:
            x, y = find_blank_tile(final_state)
            move_idx = MOVE_NAMES.index(move)
            dx, dy = MOVES[move_idx]
            new_x, new_y = x + dx, y + dy
            final_state[x][y], final_state[new_x][new_y] = final_state[new_x][new_y], final_state[x][y]
        print("\nGoal State:")
        print_puzzle(goal)
    else:
        print("\nNo solution found.")
