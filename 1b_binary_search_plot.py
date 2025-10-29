import matplotlib.pyplot as plt

# Input sizes 
n_values = [10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000, 8000, 9000, 10000]
time_taken = [0.0000000110, 0.0000000250, 0.0000000300, 0.0000000480, 0.0000000490,
              0.0000000540, 0.0000000590, 0.0000000610, 0.0000000640, 0.0000000660,
              0.0000000700, 0.0000000620]

# Plotting
plt.figure(figsize=(8,6))
plt.plot(n_values, time_taken, marker='o', linestyle='-', color='b', label="Binary Search")
plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (seconds)")
plt.title("Binary Search: Input Size vs Time Taken")
plt.grid(True, linestyle="--", alpha=0.6)
plt.legend()
plt.tight_layout()
plt.show()