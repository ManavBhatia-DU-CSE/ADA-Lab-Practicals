import matplotlib.pyplot as plt

n_values = [10, 30, 40, 45]  

recursive_times = [0.000000, 0.007000, 0.634000, 7.017000]

plt.figure(figsize=(6,4))
plt.plot(n_values, recursive_times, marker='o', color='red', label="Recursive")
plt.xlabel("Input size (n)")
plt.ylabel("Time taken (seconds)")
plt.title("Fibonacci – Recursive Time Complexity")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()