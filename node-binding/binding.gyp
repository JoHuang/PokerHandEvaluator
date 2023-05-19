{
  "targets": [
    {
      "target_name": "phe",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [ 
        "index.cc",
        "cpp/src/7462.c",
        "cpp/src/dptables.c",
        "cpp/src/evaluator5.c",
        "cpp/src/evaluator6.c",
        "cpp/src/evaluator7.c",
        "cpp/src/evaluator_omaha.c",
        "cpp/src/hash.c",
        "cpp/src/hashtable.c",
        "cpp/src/hashtable5.c",
        "cpp/src/hashtable6.c",
        "cpp/src/hashtable7.c",
        "cpp/src/rank.c",
        "cpp/src/tables_omaha.c"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "cpp/include"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}