import numpy as np
import matplotlib.pyplot as plt
import pandas as pd


csvs = ["canberra.csv", "madrid.csv", "goldstone.csv","dsn_network.csv"]
labels = ["Canberra", "Madrid", "Goldstone", "Network"]

min_dr = 1e30
max_dr = 0
# fig, ax = plt.subplot(figsize=(16,9))
plt.figure(figsize=(16,9))
for csv, label in zip(csvs, labels):
    df = pd.read_csv(csv)
    data = df.to_numpy()

    times = data[:,0]
    datarates = data[:,1]

    times = times - times[0]
    times = times/3600
    datarates = datarates / 1e6
    min_dr = min(datarates[datarates > 0].min(), min_dr)
    max_dr = max(datarates.max(), max_dr)

    plt.scatter(times, datarates, label=label)

plt.grid()
plt.ylim(min_dr*0.9,max_dr*1.1)
plt.xlabel("Hours since simulation start")
plt.ylabel("Datarate [Mbps]")
plt.legend()
plt.savefig("zero_plot.png")
plt.show()
