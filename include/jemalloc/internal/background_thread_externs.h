#ifndef JEMALLOC_INTERNAL_BACKGROUND_THREAD_EXTERNS_H
#define JEMALLOC_INTERNAL_BACKGROUND_THREAD_EXTERNS_H

extern bool opt_background_thread;
extern malloc_mutex_t background_thread_lock;
extern atomic_b_t background_thread_enabled_state;
extern size_t n_background_threads;
extern background_thread_info_t *background_thread_info;

bool background_thread_create(tsd_t *tsd, unsigned arena_ind);
bool background_threads_init(tsd_t *tsd);
bool background_threads_enable(tsd_t *tsd);
bool background_threads_disable(tsd_t *tsd);
bool background_threads_disable_single(tsd_t *tsd,
    background_thread_info_t *info);
void background_thread_interval_check(tsdn_t *tsdn, arena_t *arena,
    arena_decay_t *decay, size_t npages_new);
void background_thread_prefork0(tsdn_t *tsdn);
void background_thread_prefork1(tsdn_t *tsdn);
void background_thread_postfork_parent(tsdn_t *tsdn);
void background_thread_postfork_child(tsdn_t *tsdn);

#if defined(JEMALLOC_BACKGROUND_THREAD) || defined(JEMALLOC_LAZY_LOCK)
extern int (*pthread_create_fptr)(pthread_t *__restrict, const pthread_attr_t *,
    void *(*)(void *), void *__restrict);
void *load_pthread_create_fptr(void);
#endif

#endif /* JEMALLOC_INTERNAL_BACKGROUND_THREAD_EXTERNS_H */
