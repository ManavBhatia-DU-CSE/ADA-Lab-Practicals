import matplotlib.pyplot as plt

n_values = [10, 30, 40, 45]

iterative_times = [0.004000, 0.006000, 0.010000, 0.011000]

plt.figure(figsize=(6,4))
plt.plot(n_values, iterative_times, marker='s', color='blue', label="Iterative")
plt.xlabel("Input size (n)")
plt.ylabel("Time taken (seconds)")
plt.title("Fibonacci – Iterative Time Complexity")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()