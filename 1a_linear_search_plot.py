import matplotlib.pyplot as plt

# Input sizes
n_values = [10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000, 8000, 9000, 10000]

linear_times = [0.000000, 0.000000, 0.000000, 0.000000, 0.000001,
                0.000003, 0.000005, 0.000006, 0.000007, 0.000008, 0.000009, 0.000010]

plt.plot(n_values, linear_times, label="Linear Search", marker='o')
plt.xlabel("Input size (Number of elements, n)")
plt.ylabel("Time taken (seconds)")
plt.title("Linear Search Time Complexity")
plt.legend()
plt.grid(True)
plt.show()