let user = "";
fetch(
  `https://codeforces.com/api/user.status?handle=${user}&from=1&count=10000`
)
  .then((response) => response.text())
  .then((response) => {
    response = JSON.parse(response);
    let submissions = response?.result;
    let yesterday = [];
    let same_day_last_week = [];

    submissions.forEach((element) => {
      let diff = new Date() - new Date(element.creationTimeSeconds * 1e3);
      if (diff >= 86400000 && diff <= 2 * 86400000) {
        yesterday.push(element);
      }
      if (diff >= 604800000 && diff <= 604800000 + 86400000) {
        same_day_last_week.push(element);
      }
    });
    console.log(`-------------- Yesterday ----------------`);
    let yesterday_set = new Set();
    yesterday.forEach((element) => {
      yesterday_set.add(
        `https://codeforces.com/contest/${element.problem.contestId}/problem/${element.problem.index}`
      );
    });
    yesterday_set.forEach((element) => {
      console.log(element);
    });
    console.log(`-------------- same_day_last_week ----------------`);
    let same_day_last_week_set = new Set();
    same_day_last_week.forEach((element) => {
      same_day_last_week_set.add(
        `https://codeforces.com/contest/${element.problem.contestId}/problem/${element.problem.index}`
      );
    });
    same_day_last_week_set.forEach((element) => {
      console.log(element);
    });
  })
  .catch(function (err) {
    console.log("Unable to fetch -", err);
  });
