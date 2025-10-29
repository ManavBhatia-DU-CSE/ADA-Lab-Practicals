import matplotlib.pyplot as plt

# Input sizes
n_values = [10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000, 8000, 9000, 10000]

insertion_times = [0.000000, 0.000004, 0.000011, 0.000127, 0.000450, 0.003928, 0.010025, 0.014303, 0.018975, 0.024392, 0.030306, 0.038049]

plt.plot(n_values, insertion_times, label="Insertion Sort", marker='o')
plt.xlabel("Input size (n)")
plt.ylabel("Time taken (seconds)")
plt.title("Insertion Sort Time Complexity")
plt.legend()
plt.grid(True)
plt.show()