## 🚀 Philosophers
Dining philosophers problem is a problem created by Edsger Wybe Dijkstra in 1965 to explain the deadlock state of an operating system, which is traditionally commonly introduced in lectures on operating systems

For example, N philosophers are sitting at a round table and eating. A fork is placed between the philosophers, and the philosophers eat through the following process.

The philosopher repeats three actions:
eating ➔ sleeping ➔ thinking. When eating, both forks should be used. If you lift both forks, eat for a certain amount of time. When you're done eating, put down your fork. Not a single philosopher should die due to lack of food for a certain period of time. If all the philosophers were hungry and picked up the left forks at the same time, the right forks would have already been picked up by the philosopher sitting to their right, and everyone would be forever unable to hold the right forks. That is, there is no further progress, and the philosophers remain on standby forever. This phenomenon is called deadlock. Once in a deadlock, philosophers continue to suffer and die of starvation. The task is to implement a program that solves this problem using mutex or semaphore
---

## 📖 Subject
There is a PDF in the subject folder containing details about the project.

---

## 🖥️ Running the project

```bash
# Clone the repository
git clone https://github.com/r-moreira/42-projects.git

# Enter the project directory
cd philosophers/philo

# Build
make

# Usage :
./philo_one number_philosopher time_to_die time_to_eat time_to_sleep [number_of_time_each_philosophers_must_eat] arguments in square brackets are not required (number_of_time_each_philosophers_must_eat)

# Example :
./philo_one 4 500 200 200
```


