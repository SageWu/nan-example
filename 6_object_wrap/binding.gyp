{
  "targets": [
    {
      "target_name": "example",
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ],
      "sources": [
        "main.cc",
        "value-wrap.cc"
      ]
    }
  ]
}