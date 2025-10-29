import matplotlib.pyplot as plt

# Input sizes
n_values = [10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000, 8000, 9000, 10000]

merge_times = [0.000001, 0.000005, 0.000011, 0.000075, 0.000157, 0.000550, 0.000990, 0.001263, 0.001464, 0.001688, 0.001844, 0.002009]

plt.plot(n_values, merge_times, label="Merge Sort", marker='o')
plt.xlabel("Input size (n)")
plt.ylabel("Time taken (seconds)")
plt.title("Merge Sort Time Complexity")
plt.legend()
plt.grid(True)
plt.show()