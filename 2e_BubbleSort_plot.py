import matplotlib.pyplot as plt

# Input sizes
n_values = [10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000, 8000, 9000, 10000]

bubble_times = [0.000000, 0.000010, 0.000035, 0.000618, 0.002331, 0.017705, 0.049535, 0.067841, 0.091082, 0.145754, 0.199816, 0.256741]

plt.plot(n_values, bubble_times, label="Bubble Sort", marker='o')
plt.xlabel("Input size (n)")
plt.ylabel("Time taken (seconds)")
plt.title("Bubble Sort Time Complexity")
plt.legend()
plt.grid(True)
plt.show()