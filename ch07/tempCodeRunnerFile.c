for (i = s->num - 1; i > 0; i--) {
        // Pass
        for (j = 0; j < i; j++) {
            if (s->set[j] > s->set[j + 1]) {
                // swap
                int tmp = s->set[j];
                s->set[j] = s->set[j + 1];
                s->set[j + 1] = tmp;
            }
        }
    }