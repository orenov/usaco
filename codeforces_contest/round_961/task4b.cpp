int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int start = 0;
    while (start < n && a[start] == 1) {
      start += 1;
    }
    int64_t ans = 0;
    int last = 0;
    for (int i = start + 1; i < n; i++) {
      if (a[i] == 1) {
        ans = -1;
        break;
      }
      int cur = 0;
      auto x = a[i];
      while (x < a[i - 1]) {
        x *= x;
        cur += 1;
      }
      x = a[i - 1];
      while (last > 0 && x * x <= a[i]) {
        x *= x;
        last -= 1;
      }
      cur += last;
      ans += cur;
      last = cur;
    }
    cout << ans << '\n';
  }
  return 0;
}