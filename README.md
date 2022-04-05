<h1 align="center">Philosophers</h1>

#### In this project, you will learn the principles of threading a process and how to make threads. Also you will discover the mutex. 

## 📚 Mandatory Part 📚

- **Name of the program** : `philo`
- **Files** : [`*.c`](./src) [`philo.h`](./includes/philo.h) [`Makefile`](./Makefile)
- **Makefile rules** : `all` `clean` `fclean` `re`
- **Arguments** : number_of_philosophers time_to_die time_to_eat time_to_sleep *number_of_times_each_philosopher_must_eat. ( *note: optional argument)
- **Authorized functions** : [`memset`](https://www.tutorialspoint.com/c_standard_library/c_function_memset.htm) [`printf`](https://en.wikipedia.org/wiki/Printf_format_string) [`malloc`](https://man7.org/linux/man-pages/man3/free.3.html) [`free`](https://man7.org/linux/man-pages/man3/free.3.html) [`write`](https://man7.org/linux/man-pages/man2/write.2.html) [`close`](https://linux.die.net/man/2/close) [`usleep`](https://man7.org/linux/man-pages/man3/usleep.3.html) [`gettimeofday`](https://man7.org/linux/man-pages/man2/settimeofday.2.html) [`pthread_create`](https://man7.org/linux/man-pages/man3/pthread_create.3.html) [`pthread_detach`](https://man7.org/linux/man-pages/man3/pthread_detach.3.html) [`pthread_join`](https://man7.org/linux/man-pages/man3/pthread_join.3.html) [`pthread_mutex_init`](https://man7.org/linux/man-pages/man3/pthread_mutex_init.3p.html) [`pthread_mutex_destroy`](https://man7.org/linux/man-pages/man3/pthread_mutex_destroy.3p.html) [`pthread_mutex_lock`](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html) [`pthread_mutex_unlock`](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html)
- Every philosopher should be a thread.
- A fork beetwen every philosopher. So if there are multimple philsophers there shoud be a fork to the right and left of each other.
- To prevent multiple philosophers from using the same fork, you must protect the state each with its own mutex.
