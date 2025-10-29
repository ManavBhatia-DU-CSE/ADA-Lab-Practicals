import matplotlib.pyplot as plt

# Input sizes
n_values = [10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000, 8000, 9000, 10000]

selection_times = [0.000000, 0.000005, 0.000017, 0.000239, 0.000882, 0.007348, 0.020457, 0.029338, 0.038483, 0.048084, 0.061078, 0.084414]

plt.plot(n_values, selection_times, label="Selection Sort", marker='o')
plt.xlabel("Input size (n)")
plt.ylabel("Time taken (seconds)")
plt.title("Selection Sort Time Complexity")
plt.legend()
plt.grid(True)
plt.show()