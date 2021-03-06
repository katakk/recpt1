/* -*- tab-width: 4; indent-tabs-mode: nil -*- */
#ifndef _RECPT1_H_
#define _RECPT1_H_

#define       __PX4__   1
#define     __NO_PX4__   (!(__PX4__))

#define NUM_BSDEV       52                                      // Jacky Han Modified
#define NUM_ISDB_T_DEV  52                                      // Jacky Han Modified
#define CHTYPE_SATELLITE    0        /* satellite digital */
#define CHTYPE_GROUND       1        /* terrestrial digital */
#define MAX_QUEUE           8192
#define MAX_READ_SIZE       (188 * 87) /* 188*87=16356 splitterが188アライメントを期待しているのでこの数字とする*/
#define MAX_QUEUE_PX4       512                                                                                                  // Jacky Han Added
#define MAX_READ_SIZE_PX4   (188 * 816) /* 188*816=153408 splitterが188アライメントを期待しているのでこの数字とする*/       // Jacky Han Added
#define WRITE_SIZE          (1024 * 1024 * 2)
#define TRUE                1
#define FALSE               0

#define ISDB_T_NODE_LIMIT 24        // 32:ARIB limit 24:program maximum
#define ISDB_T_SLOT_LIMIT 8

//#define ASV5220_USE_APKEY1

typedef struct {
    int size;
#if 0
    u_char buffer[MAX_READ_SIZE];
#else
    u_char* pBuffer;        // Jacky Han Modified
#endif
} BUFSZ;

typedef struct {
    unsigned int in;        // 次に入れるインデックス
    unsigned int out;        // 次に出すインデックス
    unsigned int size;        // キューのサイズ
    unsigned int num_avail;    // 満タンになると 0 になる
    unsigned int num_used;    // 空っぽになると 0 になる
    pthread_mutex_t mutex;
    pthread_cond_t cond_avail;    // データが満タンのときに待つための cond
    pthread_cond_t cond_used;    // データが空のときに待つための cond
    BUFSZ *buffer[1];    // バッファポインタ
} QUEUE_T;

typedef struct {
    int set_freq;    // 実際にioctl()を行う値
    int type;        // チャンネルタイプ
    int add_freq;    // 追加する周波数(BS/CSの場合はスロット番号)
    char *parm_freq;    // パラメータで受ける値
} ISDB_T_FREQ_CONV_TABLE;

#endif
