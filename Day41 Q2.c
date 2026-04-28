int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};
    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    int max_freq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
        }
    }

    int max_freq_count = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == max_freq) {
            max_freq_count++;
        }
    }

    int part_count = max_freq - 1;
    int part_length = n - (max_freq_count - 1);
    int empty_slots = part_count * part_length;
    int available_tasks = tasksSize - (max_freq * max_freq_count);
    int idles = (empty_slots - available_tasks > 0) ? (empty_slots - available_tasks) : 0;

    return tasksSize + idles;
}