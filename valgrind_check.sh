#!/usr/bin/env bash
set -e

EXEC="$1"

if [ -z "$EXEC" ]; then
    echo "Usage: $0 ./ton_programme [args...]"
    exit 1
fi

shift

valgrind \
  --leak-check=full \
  --show-leak-kinds=all \
  --track-origins=yes \
  --suppressions=mlx42.supp \
  "$EXEC" "$@"
