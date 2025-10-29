import matplotlib.pyplot as plt

# Input sizes
n_values = [10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000, 8000, 9000, 10000]

quick_times = [0.000000, 0.000002, 0.000004, 0.000022, 0.000050, 0.000214, 0.000416, 0.000503, 0.000572, 0.000696, 0.000795, 0.000892]

plt.plot(n_values, quick_times, label="Quick Sort", marker='o')
plt.xlabel("Input size (n)")
plt.ylabel("Time taken (seconds)")
plt.title("Quick Sort Time Complexity")
plt.legend()
plt.grid(True)
plt.show()